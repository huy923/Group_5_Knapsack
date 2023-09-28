class Item:
    def __init__(self, value, cost):
        self.value = value
        self.cost = cost
    
def MarginalRatioThresholding(alpha, K, items, fs=0, costS=0):
    array = []
    for item in items:
        marginalRatio = item.value / item.cost
        if costS + item.cost <= K and marginalRatio >= alpha:
            array.append(item.value)
            costS += item.cost
            fs += item.value
    return array, fs, costS

items = [Item(value=3, cost=2), Item(value=4, cost=3), Item(value=5, cost=4),Item(value=7,cost=5)]
alpha = 0.5 # α ∈ (0, 1]
K = 10 
# Call the function and print the result
result_array, result_fs, result_costS = MarginalRatioThresholding(alpha, K, items)
print("Array:", result_array)
print("Total fs:", result_fs)
print("Total costS:", result_costS)