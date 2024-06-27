def convert_time_to_12_hour_format(time_str):
    hour, minute = map(int, time_str.split(':'))
    period = "AM" if hour < 12 else "PM"
    if hour == 0:
        hour = 12
    elif hour > 12:
        hour -= 12
    return f"{hour:02d}:{minute:02d} {period}"

num_test_cases = int(input())

for _ in range(num_test_cases):
    time_str = input().strip()
    print(convert_time_to_12_hour_format(time_str))
