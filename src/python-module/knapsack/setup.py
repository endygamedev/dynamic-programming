from distutils.core import setup, Extension
setup(
	name="knapsack", 
	version="1.0", 
	ext_modules=[
		Extension(
			"knapsack", ["knapsack.c"]
		)
	]
)
