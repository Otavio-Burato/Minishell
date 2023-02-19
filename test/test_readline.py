from ctypes import CDLL
import unittest

load = CDLL("./test/load.so")
class TestSanitize(unittest.TestCase):

	#never do this
	#def test_main(self):
	#	self.assertEqual(load.ft_read_line(), 0)

	def test_sanitize_line(self):
		self.assertEqual(load.ft_sanitize_line("oi"), 1)

if __name__ == '__main__':
	unittest.main()
