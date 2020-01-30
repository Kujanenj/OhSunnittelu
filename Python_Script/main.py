# This Python file uses the following encoding: utf-8

from selenium import webdriver

# import time

driver = webdriver.PhantomJS("D:/Git Veikko/OhSunnittelu/Python_Script/phantomjs.exe") # WINDOWS VERSIO - Laita polku phantomjs.exe filuun
# driver = webdriver.PhantomJS() # LINUX VERSIO

driver.get("https://www.finlandiahiihto.fi/Tulokset/Tulosarkisto") # Etsii tulosarkiston
search_bar = driver.find_element_by_id("dnn_ctr1025_Etusivu_cmdHaeTulokset").click() # Clickkaa hae kuvaketta ilman filttereitä

f = open("data.txt", "w+", encoding='utf-8') # Avaa ja kirjoittaa data.txt filuun
f.write(driver.page_source)
f.close()
driver.close()
print("Done")
