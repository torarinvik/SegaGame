from Basic import sqrt2
import unittest



class TestSqrt2(unittest.TestCase):
    def test_sqrt2(self):
        self.assertAlmostEqual(sqrt2(4), 2, delta=1e-5)
        self.assertAlmostEqual(sqrt2(9), 3, delta=1e-5)
        self.assertAlmostEqual(sqrt2(2), 1.41421356, delta=1e-5)
        self.assertAlmostEqual(sqrt2(1), 1, delta=1e-5)
        

if __name__ == '__main__':
    unittest.main()
