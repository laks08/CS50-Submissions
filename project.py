import csv
import pandas
from googletrans import Translator

while True:
    print("****** TRUE TRANSLATE ******")
    lang_select = input("Enter the Destination Language: ")
    lang_select.capitalize()
    if len(lang_select) > 0:
        # print(lang_select)
        lang_list = []
        with open('language_codes.csv', 'r') as file:
            dataset = csv.reader(file, delimiter=',')
            for row in dataset:
                lang_list.append(row)

            for i in range(1,len(lang_list)):
                a = lang_list[i][0]
                if a == lang_select:
                    break
                else:
                    continue

            if a == lang_select:
                b = lang_list[i][1]
                input_text = input("Enter the text to be converted: ")
                translator = Translator()
                translated_text = translator.translate(input_text, dest = b)
                c = translated_text.text
                print(c)

            else:
                print("Entered language is not available")
                ans = input("Do you want to see the avaiable languages? (Y/N) ")
                ans.lower()
                if ans == 'n':
                    continue
                else:
                    print(pandas.DataFrame(lang_list))
        break
    else:
        continue



