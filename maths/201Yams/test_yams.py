#!/usr/bin/env python3

import unittest
import sys
import io
import math
from contextlib import redirect_stdout
import a201yams

class TestYams(unittest.TestCase):

    # Testing "get_apparition" function
    def test_get_apparition(self):
        self.assertEqual(get_apparition(2), 2)
        self.assertEqual(get_apparition(5), 1)
        self.assertEqual(get_apparition(3), 3)

    # Testing "error_number" function
    def test_error_number(self):
        self.assertEqual(error_number("2", 1), 2)
        self.assertRaises(Exception, error_number, "-1", 1)
        self.assertRaises(Exception, error_number, "7", 1)
        self.assertRaises(Exception, error_number, "test", 1)

    # Testing "binomial_function" function
    def test_binomial_function(self):
        self.assertAlmostEqual(binomial_function(5, 3), 0.032)
        self.assertAlmostEqual(binomial_function(3, 2), 0.421875)

    # Testing "result_function" function
    def test_result_function(self):
        self.assertAlmostEqual(result_function(3, 3), 42.13)
        self.assertAlmostEqual(result_function(4, 4), 9.72)

    # Testing "straight_function" function
    def test_straight_function(self):
        self.assertAlmostEqual(straight_function(2), 2.78)
        self.assertAlmostEqual(straight_function(1), 11.57)

    # Testing "full_function" function
    def test_full_function(self):
        self.assertAlmostEqual(full_function(3, 5), 0.08)
        self.assertAlmostEqual(full_function(2, 2), 2.78)

    # Testing "search_compute" function
    def test_search_compute(self):
        out = io.StringIO()
        with redirect_stdout(out):
            search_compute("three_5")
        self.assertEqual(out.getvalue().strip(), "Chances to get a 5 three-of-a-kind: 42.13%")

if __name__ == '__main__':
    unittest.main()