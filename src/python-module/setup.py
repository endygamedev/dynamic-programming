from distutils.core import setup, Extension

module = Extension (
        'fdpp',
        sources = ['module.c']
)

setup (
    name = 'fdpp',
    version = '1.0',
    description = 'doc',
    ext_modules = [module]
)
