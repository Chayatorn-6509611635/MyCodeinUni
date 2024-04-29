def ask(prompt, retries=4, output='Error'):
    for _ in range(retries):
        response = input(prompt).lower()
        if response in ['y', 'yes']:
            return True
        if response in ['n', 'no']:
            return False
        print(output)
        
print(ask('Want to know the answer?', 5))