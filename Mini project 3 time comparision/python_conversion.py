import time

def convert_to_uppercase(input_file, output_file):
    start_time = time.time()

    with open(input_file, 'r') as input_file:
        with open(output_file, 'w') as output_file:
            for line in input_file:
                converted_line = line.upper()
                output_file.write(converted_line)

    end_time = time.time()
    execution_time = end_time - start_time

    print(f"File conversion complete: {input_file} -> {output_file}")
    print(f"Execution time for {input_file}: {execution_time} seconds")

# List of file pairs (input file, output file)
file_pairs = [
     ("file 200MB.txt", "output200.txt"),
        ("file 400MB.txt", "output400.txt"),
        ("file 600MB.txt", "output600.txt"),
        ("file 800MB.txt", "output800.txt"),
        ("file 1000MB.txt", "output1000.txt"),
    # Add more file pairs here if needed
]

for input_file, output_file in file_pairs:
    convert_to_uppercase(input_file, output_file)
