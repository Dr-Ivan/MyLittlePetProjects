def printLog(iteration, curSymbol, curState, replacement, direction, newState):
    print(f'T{iteration}: {curSymbol}, {curState} ----> {replacement}, {direction.capitalize()}, {newState}')


def turingMacineSimulation(line, pointer):
    state = 's0'
    i = 0
    direction = ''
    current = ''
    while True:
        newSymbol = ''
        i += 1
        current = line[pointer]
        prevState = state
        if state == 's0':
            if line[pointer] == 'm':
                state = 's1'
                pointer -= 1
                direction = 'L'
            elif line[pointer] == '0':
                state = 's2'
                pointer += 1
                direction = 'R'
            elif line[pointer] == '1':
                state = 's2'
                pointer += 1
                direction = 'R'
            elif line[pointer] == '2':
                state = 's2'
                pointer += 1
                direction = 'R'
        elif state == 's1':
            if line[pointer] == 'm':
                state = 's0'
                line = line[:pointer] + '1' + line[pointer+1:]
                newSymbol = '1'
                direction = 'N'
            elif line[pointer] == '0':
                state = 's0'
                line = line[:pointer] + '1' + line[pointer+1:]
                newSymbol = '1'
                direction = 'N'
            elif line[pointer] == '1':
                state = 's0'
                line = line[:pointer] + '2' + line[pointer+1:]
                newSymbol = '2'
                direction = 'N'
            elif line[pointer] == '2':
                state = 's1'
                line = line[:pointer] + '0' + line[pointer+1:]
                newSymbol = '0'
                pointer -= 1
                direction = 'L'
        elif state == 's2':
            if line[pointer] == 'm':
                state = 's1'
                pointer -= 1
                direction = 'L'
            elif line[pointer] == '0':
                state = 's2'
                pointer += 1
                direction = 'R'
            elif line[pointer] == '1':
                state = 's2'
                pointer += 1
                direction = 'R'
            elif line[pointer] == '2':
                state = 's2'
                pointer += 1
                direction = 'R'
        newSymbol = newSymbol if newSymbol else current
        printLog(i, current, prevState, newSymbol, direction, state)
        if state == 's0':
            return line


if __name__ == "__main__":
    print("Реализация алгоритма машины Тьюринга для инкремента троичного числа.")
    tape = input("Введите ленту для машины Тьюринга (символ m для обозначения m0): ")
    start = int(input("Введите индекс (начиная с единицы), где изначально находится управляющая головка: "))
    tape = f'm{tape.lower()}m'

    if any([x not in "m0123" for x in tape ]):
        print("Неверный алфавит для троичной системы.")
        exit(0)

    res = turingMacineSimulation(tape, start)
    print("Результат:")
    print("Исходная строка: ", tape)
    print("Выходная строка: ", res)

