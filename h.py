def compute(arr):
    
    thousand=int(arr[0][0])
    hundred=int(arr[0][1])
    ten=int(arr[0][2])
    unit=int(arr[0][3])
    for i in range(1,3):
        if int(arr[i][0])<thousand:
            thousand = int(arr[i][0])
        if int(arr[i][1])>hundred:
            hundred = int(arr[i][0])
        if int(arr[i][2])<ten:
            ten = int(arr[i][0])
        if int(arr[i][3])>unit:
            unit = int(arr[i][0])
    res = str(thousand)+str(hundred)+str(ten)+str(unit)
    return res
        


arr = list(input().strip().split(" "))
# print(arr)
res = compute(arr)
print(res)