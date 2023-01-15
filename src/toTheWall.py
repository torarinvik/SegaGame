import pygame
import random

friction = 0.02
#elasticity = 1
balls = []
walls = []


class Vector:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def add(self, vec):
        """Vector addition"""
        return Vector(self.x + vec.x, self.y + vec.y)

    def subtr(self, vec):
        """Vector subtraction"""
        return Vector(self.x - vec.x, self.y - vec.y)

    def mag(self):
        """Get magnitude"""
        return (self.x ** 2 + self.y ** 2) ** 0.5

    def mult(self, n):
        """Vector multiplied by constant"""
        return Vector(self.x * n, self.y * n)

    def normal(self):
        """Get normal"""
        return Vector(-self.y, self.x).unit()

    def unit(self):
        """Get unit vector"""
        if self.mag() == 0:
            return Vector(0, 0)
        else:
            return Vector(self.x / self.mag(), self.y / self.mag())

    @staticmethod
    def dot(vec1, vec2):
        """Get dot product of two vectors"""
        return vec1.x * vec2.x + vec1.y * vec2.y


class Ball:

    # Init method or constructor
    def __init__(self, mass, radius, color, x, y, vx, vy):
        self.r = radius
        self.mass = mass
        if self.mass == 0:
            self.inv_mass = 0
        else:
            self.inv_mass = 1 / self.mass
        self.pos = Vector(x, y)
        self.vel = Vector(vx, vy)
        self.acc = Vector(0, 0)
        self.acc_mult = 1
        self.elasticity = 0.8
        balls.append(self)
        self.color = color

        self.originalpos = self.pos
        self.originalvel = self.vel

    def reposition(self):
        self.acc = self.acc.unit().mult(self.acc_mult)
        self.vel = self.vel.add(self.acc)
        self.vel = self.vel.mult(1 - friction)
        self.pos = self.pos.add(self.vel)

    def reset(self):
        self.pos = self.originalpos
        self.vel = self.originalvel

    def draw(self):
        pygame.draw.circle(window, self.color, (self.pos.x, self.pos.y), self.r)  # DRAW CIRCLE


class Wall:
    def __init__(self, x1, y1, x2, y2):
        self.start = Vector(x1, y1)
        self.end = Vector(x2, y2)
        walls.append(self)

    def drawWall(self):
        pygame.draw.line(window, self.color, (self.x1, self.y1), (self.x2, self.y2))  # DRAW CIRCLE

    def wallUnit(self):
        return self.end.subtr(self.start).unit()


def coll_det_bb(b1, b2):
    """Collision detection. Returns true if collision."""
    if (b1.r + b2.r >= b2.pos.subtr(b1.pos).mag()):
        return True
    else:
        return False


def pen_res_bb(b1, b2):
    """Prevent balls from overlapping"""
    dist = b1.pos.subtr(b2.pos)
    pen_depth = b1.r + b2.r - dist.mag()
    pen_res = dist.unit().mult(pen_depth / (b1.inv_mass + b2.inv_mass))
    b1.pos = b1.pos.add(pen_res.mult(b1.inv_mass))
    b2.pos = b2.pos.add(pen_res.mult(-b2.inv_mass))


def coll_res_bb(b1, b2):
    """Collision response"""
    normal = b1.pos.subtr(b2.pos).unit()
    relVel = b1.vel.subtr(b2.vel)
    sepVel = Vector.dot(relVel, normal)
    new_sepVel = -sepVel * min(b1.elasticity, b2.elasticity)
    vsep_diff = new_sepVel - sepVel
    impulse = vsep_diff / (b1.inv_mass + b2.inv_mass)
    impulseVec = normal.mult(impulse)
    b1.vel = b1.vel.add(impulseVec.mult(b1.inv_mass))
    b2.vel = b2.vel.add(impulseVec.mult(-b2.inv_mass))


def closestPointBW(b1, w1):
    ballToWallStart = w1.start.subtr(b1.pos)
    if Vector.dot(w1.wallUnit(), ballToWallStart) > 0:
        return w1.start
    wallEndToBall = b1.pos.subtr(w1.end)
    if Vector.dot(w1.wallUnit(), wallEndToBall) > 0:
        return w1.end
    closestDist = Vector.dot(w1.wallUnit(), ballToWallStart)
    closestVect = w1.wallUnit().mult(closestDist)
    return w1.start.subtr(closestVect)


def coll_det_bw(b1, w1):
    ballToClosest = closestPointBW(b1, w1).subtr(b1.pos)
    if ballToClosest.mag() <= b1.r:
        return True


def pen_res_bw(b1, w1):
    penVect = b1.pos.subtr(closestPointBW(b1, w1))
    b1.pos = b1.pos.add(penVect.unit().mult(b1.r - penVect.mag()))


def coll_res_bw(b1, w1):
    normal = b1.pos.subtr(closestPointBW(b1, w1)).unit()
    sepVel = Vector.dot(b1.vel, normal)
    new_sepVel = -sepVel * b1.elasticity
    vsep_diff = sepVel - new_sepVel
    b1.vel = b1.vel.add(normal.mult(-vsep_diff))


red = (255, 100, 100)
green = (100, 255, 100)
blue = (100, 100, 255)
magenta = (250, 100, 250)

ballsize = 43
ball = Ball(250, ballsize, red, 100, 500, 0, 0)
ball2 = Ball(650, ballsize+50, green, 400, 500, 0, 0)
ball3 = Ball(120, ballsize-15, blue, 500, 200, 0, 0)
ball4 = Ball(250, ballsize, magenta, 360, 360, 0, 0)

xdim = 800
ydim = 600

wall = Wall(0, 0, 0, ydim)
wall = Wall(0, 0, xdim, 0)
wall = Wall(xdim, 0, xdim, ydim)
wall = Wall(0, ydim, xdim, ydim)

window = pygame.display.set_mode((xdim, ydim))
clock = pygame.time.Clock()

active = True
while active:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            active = False

    keys = pygame.key.get_pressed()
    ball.acc.x = 0.01 * (-keys[pygame.K_LEFT] + keys[pygame.K_RIGHT])
    ball.acc.y = 0.01 * (-keys[pygame.K_UP] + keys[pygame.K_DOWN])

    if keys[pygame.K_r]:
        for b in balls[1::]:
            b.reset()

    window.fill('black')

    for ind, bol in enumerate(balls):
        bol.draw()

        # walls
        for i in range(len(walls)):
            if coll_det_bw(balls[ind], walls[i]):
                pen_res_bw(balls[ind], walls[i])
                coll_res_bw(balls[ind], walls[i])

        # balls
        for i in range(ind + 1, len(balls)):
            if coll_det_bb(balls[ind], balls[i]):
                pen_res_bb(balls[ind], balls[i])
                coll_res_bb(balls[ind], balls[i])
        bol.reposition()

    pygame.display.update()
    clock.tick(60)
