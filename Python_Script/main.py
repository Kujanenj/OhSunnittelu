# This Python file uses the following encoding: utf-8

from selenium import webdriver

import json

# Veikon polku: D:\Git Veikko\OhSunnittelu\Python_Script\phantomjs.exe
# Jonkun polku: E:\Gitin repo\ohSuunnittelu\OhSunnittelu\Python_Script\phantomjs.exe

driver = webdriver.PhantomJS("D:\Git Veikko\OhSunnittelu\Python_Script\phantomjs.exe") # WINDOWS VERSIO - Laita polku phantomjs.exe filuun
#driver = webdriver.PhantomJS() # LINUX VERSIO

driver.get("https://www.finlandiahiihto.fi/Tulokset/Tulosarkisto") # Etsii tulosarkiston


# Sukupuoli valuet: kaikki, M, N
# Ikäsarja valuet: kaikki, alle35, 35, 40, 45, 50, 55, 60, 65, 70, 75, yli80
# Matka valuet: kaikki, P50, V50, P100, P32, V20, V32, V20jun, P42, V42, V32, P20,
#               P30, P44, P60, P62, P25, P32, P35, P45, P52, P53, P75, V30, V45, V53, V75
# Vuosi valuet: kaikki, 2019-1974 yksittäin

# Dictissä 4 ensimmäistä drop down valikkoja, loput inputteja
exampledict = {
    "dnn$ctr1025$Etusivu$ddlVuosi2x" : "2019",
    "dnn$ctr1025$Etusivu$ddlMatka2x" : "P50",
    "dnn$ctr1025$Etusivu$ddlIkaluokka2" : "kaikki",
    "dnn$ctr1025$Etusivu$ddlKansalaisuus2x" : "",
    "dnn$ctr1025$Etusivu$chkLstSukupuoli2" : "kaikki",
    "dnn$ctr1025$Etusivu$txtHakuEtunimi2" : "Veikko",
    "dnn$ctr1025$Etusivu$txtHakuSukunimi2" : "",
    "dnn$ctr1025$Etusivu$txtHakuPaikkakunta2" : "",
    "dnn$ctr1025$Etusivu$txtHakuJoukkue2" : ""
}

dict = {}

# Lukee json filun ja muodostaa, siitä dictin
with open('D:\Git Veikko\OhSunnittelu\Python_Script\parameters.txt', 'r') as f:
    for line in f:
        key, value = line.split(":")
        dict[key] = value

# Asettaa elementeille valuet dictin avulla
for x in range(0, 8):
    driver.find_element_by_name(list(dict.keys())[x]).send_keys(list(dict.values())[x])



search_bar = driver.find_element_by_id("dnn_ctr1025_Etusivu_cmdHaeTulokset").click() # Clickkaa hae kuvaketta ilman filttereitä

f = open("data.txt", "w+", encoding='utf-8') # Avaa ja kirjoittaa data.txt filuun
f.write(driver.page_source)
f.close()
driver.close()
print("Done")
