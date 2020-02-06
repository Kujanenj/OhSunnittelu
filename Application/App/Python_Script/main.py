# This Python file uses the following encoding: utf-8
# Sukupuoli valuet: kaikki, M, N
# Ikäsarja valuet: kaikki, alle35, 35, 40, 45, 50, 55, 60, 65, 70, 75, yli80
# Matka valuet: kaikki, P50, V50, P100, P32, V20, V32, V20jun, P42, V42, V32, P20,
#               P30, P44, P60, P62, P25, P32, P35, P45, P52, P53, P75, V30, V45, V53, V75
# Vuosi valuet: kaikki, 2019-1974 yksittäin

from selenium import webdriver
import json

# Phantomjs.exe tulee olla C++ build kansiossa kun yrität buildata requesteriä
#driver = webdriver.PhantomJS("../../Application/Core/Python_Script/phantomjs.exe") # WINDOWS VERSIO - Laita polku phantomjs.exe filuun
driver = webdriver.PhantomJS() # LINUX VERSIO

driver.get("https://www.finlandiahiihto.fi/Tulokset/Tulosarkisto") # Etsii tulosarkiston

dict = {}

# Lukee json filun c++ buildista ja muodostaa, siitä dictin
with open('params.json', 'r') as f:
    dict = json.load(f)

# Asettaa elementeille valuet dictin avulla
for x in range(0, 8):
    driver.find_element_by_name(list(dict.keys())[x]).send_keys(list(dict.values())[x])

# Clickkaa hae kuvaketta
search_bar = driver.find_element_by_id("dnn_ctr1025_Etusivu_cmdHaeTulokset").click()

# Avaa ja kirjoittaa data.txt filuun
f = open("../../Application/Data/data.txt", "w+", encoding='utf-8')
f.write(driver.page_source)
f.close()
driver.close()
print("Done")
