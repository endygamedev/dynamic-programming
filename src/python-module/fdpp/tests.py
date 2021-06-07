import fdpp
from functools import wraps


def test_deco(func):
    @wraps(func)
    def inner(*args, **kwargs):
        res = func(*args, **kwargs)
        print(f"* {func.__name__}({args}) = {func(*args, **kwargs)} --- TEST PASSED\n")
        return res
    return inner


print("\nFAVORITE DYNAMIC PROGRAMMING PROBLEMS TESTS\n\n")
test_deco(fdpp.min_matrix_path)([[4, 7, 8, 6, 4], [6, 7, 3, 9, 2], [3, 8, 1, 2, 4], [7, 1, 7, 3, 7], [2, 9, 8, 9, 3]])
test_deco(fdpp.coin_change)([1, 3, 5, 7], 8)
test_deco(fdpp.const_cost_matrix_path)([[4, 7, 1, 6], [5, 7, 3, 9], [3, 2, 1, 2], [7, 1, 6, 3]], 25)
test_deco(fdpp.const_cost_matrix_path)([[4, 7, 1, 6], [5, 7, 3, 9], [3, 2, 1, 2], [7, 1, 6, 3]], 25)
test_deco(fdpp.levenshtein_distance)("kitten", "sitting")
test_deco(fdpp.matrix_chain_multiplication)([20, 40, 15, 30, 6])
test_deco(fdpp.matrix_chain_multiplication)([20, 40, 15, 30, 6])
test_deco(fdpp.min_matrix_path)([[4, 7, 1, 6], [5, 7, 3, 9], [3, 2, 1, 2], [7, 1, 6, 3]])
test_deco(fdpp.binary_strings_without_ones)(27)
test_deco(fdpp.rod_cut)([1, 5, 8, 9, 10, 17, 20], 6)
