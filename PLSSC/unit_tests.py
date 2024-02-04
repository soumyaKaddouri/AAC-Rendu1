import unittest
from algo_plssc import taille_plssc
from algo_plssc import plssc

X = (20, 23, 75, 18, 54, 6, 3, 18)
Y = (6, 23, 20, 18, 6, 54, 3, 13, 6, 18)
PLSSC_ATTENDUE = (20, 18, 54, 6, 18)

class TestPlusLongueSousSequanceCommune(unittest.TestCase):
    def test_taille_plssc(self):
        self.assertEqual(taille_plssc(X, Y), len(PLSSC_ATTENDUE))

    def test_plssc(self):
        self.assertEqual(plssc(X, Y), PLSSC_ATTENDUE)


if __name__ == '__main__':
    unittest.main()