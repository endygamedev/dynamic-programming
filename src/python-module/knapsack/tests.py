import knapsack


def view(knap):
    print(f"* Knapsack capacity: {knap.w()}")
    print(f"* Number of items in knapsack: {knap.n()}")
    print(f"* Weights for each item: {knap.weights()}")
    print(f"* Values for each item: {knap.values()}")
    print(f"* Optimal profit: {knap.val()}")
    print(f"* Mask of items: {knap.items()}\n\n")


if __name__ == '__main__':
    print("\nKNAPSACK TESTS\n")
    print("Ex.1")
    w1 = 26
    weights1 = [12, 7, 11, 8, 9]
    values1 = [24, 13, 23, 15, 16]
    knap1 = knapsack.Knapsack(w1, weights1, values1)
    view(knap1)

    print("Ex.2")
    w2 = 190
    weights2 = [56, 59, 80, 64, 75, 17]
    values2 = [50, 50, 64, 46, 50, 5]
    knap2 = knapsack.Knapsack(w2, weights2, values2)
    view(knap2)

    print("Ex.3")
    w3 = 170
    weights3 = [41, 50, 49, 59, 55, 57, 60]
    values3 = [442, 525, 511, 593, 546, 564, 617]
    knap3 = knapsack.Knapsack(w3, weights3, values3)
    view(knap3)
