num_test_cases = 1

for _ in range(num_test_cases):
 
    total_apples = int(input())
    klaudia_extra = int(input())

   
    klaudia_apples = (total_apples + klaudia_extra) // 2
    natalia_apples = total_apples - klaudia_apples

    print(klaudia_apples)
    print(natalia_apples)
