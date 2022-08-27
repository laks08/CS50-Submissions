# TODO
def main():
    text = input("text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = sentence_count(text)
    L = (letters / words) * 100
    # print("L",L)
    S = (sentences / words) * 100
    # print("S",S)
    grade = (0.0588 * L) - (0.296 * S) - 15.8

    if grade > 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print("Grade :",int(grade))


def count_letters(text):
    l_count = sum(not chr.isspace() for chr in text)
    # print(l_count)
    return l_count


def count_words(text):
    w_count = len(text.split())
    # print(w_count)
    return w_count


def sentence_count(text):
    s_count = text.count('.') + text.count('?') + text.count('!')
    # print(s_count)
    return s_count


main()