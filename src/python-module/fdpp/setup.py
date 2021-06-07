from distutils.core import setup, Extension


module = Extension (
        'fdpp',
        sources = ['module.c']
)


setup (
    name = 'fdpp',
    version = '1.0',
    description = 'Favorite dynamic programming problems',
    ext_modules = [module]
)
