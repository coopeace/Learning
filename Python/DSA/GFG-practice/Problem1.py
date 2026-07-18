sum=start=end = 0
target = 42
arr =[7,31,14,19,1,42,13,6,11,10,25,38,49,34,46,42,3,1]
sub_array = []
res = []

while (sum < target and end!=len(arr)):
    sum+=arr[end]
    sub_array.append(arr[end])
    end+=1
    while(sum > target):
        sum-=arr[start]
        del sub_array[0]
        start+=1
    if(sum==target):
        break

if (sum ==0 or sum!=target):
    res.append(-1)
else:
    res.append(start+1)
    res.append(end)

print(res)
