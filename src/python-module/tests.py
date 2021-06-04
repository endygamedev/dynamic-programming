import fdpp
import knapsack
import change_making


fstr = 20*'=' + '%s' + 20*'=' + '\n' + 10*'-' + '%s' + 10*'-'
print(fstr % ("min_sum_partition", fdpp.min_sum_partition([10, 20, 15, 5, 25])))
