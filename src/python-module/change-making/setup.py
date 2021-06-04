from distutils.core import setup, Extension
setup(
	name="change_making",
	version="1.0",
	ext_modules=[
		Extension(
			"change_making", ["change-making.c"]
		)
	]
)
