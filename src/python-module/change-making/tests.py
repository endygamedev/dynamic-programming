import change_making


def view(cm):
    print(f"* Amount: {cm.amount()}")
    print(f"* Number of coins: {cm.n()}")
    print(f"* Type of coins: {cm.coins()}")
    print(f"* Mask of coins: {cm.change()}")
    print(f"* Value: {cm.val()}\n\n")


if __name__ == '__main__':
    print("\nCOIN CHANGE-MAKING\n")
    print("Ex. 1")
    amount1 = 29
    coins1 = [1, 4, 5, 8, 11]
    cm1 = change_making.ChangeMaking(amount1, coins1)
    view(cm1)

    print("Ex. 2")
    amount2 = 96
    coins2 = [1, 5, 10, 25, 50, 100]
    cm2 = change_making.ChangeMaking(amount2, coins2)
    view(cm2)

    print("Ex. 3")
    amount3 = 96
    coins3 = [1, 2, 6, 12, 24, 48, 60]
    cm3 = change_making.ChangeMaking(amount3, coins3)
    view(cm3)
