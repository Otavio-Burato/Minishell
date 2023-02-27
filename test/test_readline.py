from ctypes import *
import unittest

load = CDLL("./test/load.so")
class TestSanitize(unittest.TestCase):

	#never do this
	#def test_main(self):
	#	self.assertEqual(load.ft_read_line(), 0)

	def test_trim_in_side(self):
		cstring = c_char_p(b"  ls  ")
		load.ft_sanitize_line.restype = c_char_p
		result = load.ft_sanitize_line(cstring)
		self.assertEqual(cast(result, c_char_p).value, b"ls")

	def test_trim_inside(self):
		cstring = c_char_p(b"  ls      -l  ")
		load.ft_sanitize_line.restype = c_char_p
		result = load.ft_sanitize_line(cstring)
		self.assertEqual(cast(result, c_char_p).value, b"ls -l")

	def test_trim_mult_flag(self):
		cstring = c_char_p(b"  ls      -l     -a  ")
		load.ft_sanitize_line.restype = c_char_p
		result = load.ft_sanitize_line(cstring)
		self.assertEqual(cast(result, c_char_p).value, b"ls -l -a")

	def test_trim_no_needed(self):
		cstring = c_char_p(b"ls -la")
		load.ft_sanitize_line.restype = c_char_p
		result = load.ft_sanitize_line(cstring)
		self.assertEqual(cast(result, c_char_p).value, b"ls -la")

	def test_trim_no_needed2(self):
		cstring = c_char_p(b"ls")
		load.ft_sanitize_line.restype = c_char_p
		result = load.ft_sanitize_line(cstring)
		self.assertEqual(cast(result, c_char_p).value, b"ls")

	def test_trim_with_quotes(self):
		cstring = c_char_p(b'echo -n   "    teste"')
		load.ft_sanitize_line.restype = c_char_p
		result = load.ft_sanitize_line(cstring)
		self.assertEqual(cast(result, c_char_p).value, b'echo -n "    teste"')

		cstring = c_char_p(b"echo -n   '    teste'  -l")
		load.ft_sanitize_line.restype = c_char_p
		result = load.ft_sanitize_line(cstring)
		self.assertEqual(cast(result, c_char_p).value, b"echo -n '    teste' -l")

		cstring = c_char_p(b'echo -n   "   \'  haha  \' teste"')
		load.ft_sanitize_line.restype = c_char_p
		result = load.ft_sanitize_line(cstring)
		self.assertEqual(cast(result, c_char_p).value, b'echo -n "   \'  haha  \' teste"')

if __name__ == '__main__':
	unittest.main()
