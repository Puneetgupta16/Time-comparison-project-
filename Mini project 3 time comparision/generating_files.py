import random
import string

def generate_text_file(file_path, file_size_bytes):
    with open(file_path, 'w') as file:
        bytes_written = 0
        while bytes_written < file_size_bytes:
            text = ''.join(random.choices(string.ascii_letters  + ' ', k=1024))
            bytes_to_write = min(file_size_bytes - bytes_written, len(text))
            file.write(text[:bytes_to_write])
            bytes_written += bytes_to_write

    print(f"Text file '{file_path}' generated with size {file_size_bytes} bytes.")


generate_text_file('file 200MB.txt', 200000000)
generate_text_file('file 400MB.txt', 400000000)
generate_text_file('file 600MB.txt', 600000000)
generate_text_file('file 800MB.txt', 800000000)
generate_text_file('file 1000MB.txt', 1000000000)
