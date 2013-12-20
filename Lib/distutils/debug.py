import os

# This module should be kept compatible with Python 1.5.2.

__revision__ = "$Id: debug.py 29762 2002-11-19 13:12:28Z akuchling $"

# If DISTUTILS_DEBUG is anything other than the empty string, we run in
# debug mode.
DEBUG = os.environ.get('DISTUTILS_DEBUG')

