# This Python file uses the following encoding: utf-8

from selenium import webdriver

# import time

#driver = webdriver.PhantomJS("E:\Gitin repo\ohSuunnittelu\OhSunnittelu\Python_Script\phantomjs.exe") # WINDOWS VERSIO - Laita polku phantomjs.exe filuun
driver = webdriver.PhantomJS() # LINUX VERSIO

driver.get("https://www.finlandiahiihto.fi/Tulokset/Tulosarkisto") # Etsii tulosarkiston


# string vuosi = "dnn$ctr1025$Etusivu$ddlVuosi2x"
# string matka = "dnn$ctr1025$Etusivu$ddlMatka2x"
# string sukupuoli = "dnn$ctr1025$Etusivu$chkLstSukupuoli2"
# string ikaluokka = "dnn$ctr1025$Etusivu$ddlIkaluokka2"
# string etunimi = "dnn$ctr1025$Etusivu$txtHakuEtunimi2"
# string sukunimi = "dnn$ctr1025$Etusivu$txtHakuSukunimi2"
# string paikkakunta = "dnn$ctr1025$Etusivu$txtHakuPaikkakunta2"
# string kansallisuus = "dnn$ctr1025$Etusivu$ddlKansalaisuus2x"
# string joukkue = "dnn$ctr1025$Etusivu$txtHakuJoukkue2"

# 5 Elementtiä, johon input value/radio button
#for x in range(0, 4):
#    driver.find_element_by_name("key").sendKeys("value")
# 4 Elementtiä, johon dropdown valikko
#for y in range(0, 3):
#    driver.find_element_by_name("key").selectByValue("value")



search_bar = driver.find_element_by_id("dnn_ctr1025_Etusivu_cmdHaeTulokset").click() # Clickkaa hae kuvaketta ilman filttereitä

f = open("data.txt", "w+", encoding='utf-8') # Avaa ja kirjoittaa data.txt filuun
f.write(driver.page_source)
f.close()
driver.close()
print("Done")
