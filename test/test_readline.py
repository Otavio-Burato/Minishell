from ctypes import *
import unittest

load = CDLL("./test/load.so")

def ft_run(value: bytes) -> bytes:
	cstring = c_char_p(value)
	load.ft_sanitize_line.restype = c_char_p
	result = load.ft_sanitize_line(cstring)
	return cast(result, c_char_p).value

class TestSanitize(unittest.TestCase):

	@unittest.skip
	def test_trim_in_side(self):
		self.assertEqual(ft_run(b"  ls  "), b"ls")

	@unittest.skip
	def test_trim_inside(self):
		self.assertEqual(ft_run(b"  ls      -l  "), b"ls -l")

	@unittest.skip
	def test_trim_mult_flag(self):
		self.assertEqual(ft_run(b"  ls      -l     -a  "), b"ls -l -a")

	@unittest.skip
	def test_trim_no_needed(self):
		self.assertEqual(ft_run(b"ls -la"), b"ls -la")

	@unittest.skip
	def test_trim_no_needed2(self):
		self.assertEqual(ft_run(b"ls"), b"ls")

	@unittest.skip
	def test_trim_with_quotes(self):
		self.assertEqual(ft_run(b'echo -n   "    teste"'), b'echo -n "    teste"')
		self.assertEqual(ft_run(b"echo       -n   '    teste'  -l"), b"echo -n '    teste' -l")
		self.assertEqual(ft_run(b'echo -n   "   \'  haha  \' teste"'), b'echo -n "   \'  haha  \' teste"')
		self.assertEqual(ft_run(b'echo   -n "   \'  haha  \' teste"    '), b'echo -n "   \'  haha  \' teste"')
		self.assertEqual(ft_run(b'echo   -n "   \'  haha  \' teste   "    '), b'echo -n "   \'  haha  \' teste   "')
