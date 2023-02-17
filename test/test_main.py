from ctypes import CDLL
import unittest

main = CDLL("./test/main.so")
class TestMain(unittest.TestCase):

    def test_add_one(self):
        self.assertEqual(main.add_one(6), 7)

if __name__ == '__main__':
    unittest.main()