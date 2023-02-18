from ctypes import CDLL
import unittest

load = CDLL("./test/load.so")

#class TestMain(unittest.TestCase):

	#never do this
	#def test_main(self):
	#	self.assertEqual(load.main(1 , 0, 0), 0)


if __name__ == '__main__':
	unittest.main()
