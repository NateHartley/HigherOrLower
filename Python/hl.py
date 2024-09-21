import random

while True:
    score = 0

    while True:
        print("-----------------------------------------------------------------------------------------------------")
        guess1 = random.randint(1, 10)
        print("The computer has picked the number ", guess1)
        highlow = str(input("Is the computer's second number going to be higher (h) or lower (l) than the first? "))
        print('\n')
        guess2 = random.randint(1, 10)

        if highlow == 'h' or highlow == 'l':
            if guess1 > guess2 and highlow == 'l':
                print(f'Correct! {guess2} is smaller than {guess1}')
                score = score+100
                print("+ 100 points!")
                print("Your score = ", score, '\n')
            elif guess1 < guess2 and highlow == 'h':
                print(f'Correct! {guess2} is larger than {guess1}')
                score = score + 100
                print("+ 100 points!")
                print("Your score = ", score, '\n')
            elif guess1 > guess2 and highlow == 'h':
                print(f'Wrong! {guess2} is smaller than {guess1}')
                print("You finished the game with a score of ", score, '\n')
                break
            elif guess1 < guess2 and highlow == 'l':
                print(f'Wrong! {guess2} is larger than {guess1}')
                print("You finished the game with a score of ", score, '\n')
                break
            else:
                print(f'{guess1} and {guess2} are the same!')
                print("+ 0 points \n")
        else:
            print("Please chose either higher (h) or lower (l)")

    yn = str(input("Play again? (y/n) "))
    if yn == 'n':
        break