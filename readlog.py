import re
from collections import defaultdict
from datetime import datetime

def count_lines_per_second(file_name):
    line_count = 0
    lines_per_second = defaultdict(int)
    with open(file_name, 'r') as file:
        for line in file:
            timestamp_str = line[:19]
            timestamp = datetime.strptime(timestamp_str, '%Y-%m-%d %H:%M:%S')
            lines_per_second[timestamp] += 1
    return lines_per_second

def calculate_average_time(file_name):

    pattern = re.compile(r'all\[(\d+)\]ms')
    data_per_minuete = defaultdict(list)

    with open(file_name, 'r') as file:
        for line in file:
            timestamp_str = line[:19]
            timestamp = datetime.strptime(timestamp_str, '%Y-%m-%d %H:%M:%S')

            match = pattern.search(line)

            if match:
                value = int(match.group(1))
                minute = timestamp.replace(second=0)

                data_per_minuete[minute].append(value)
    average_per_minute = {minute: sum(values) / len(values) for minute, values in data_per_minuete.items()}
    return average_per_minute