from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

driver = webdriver.Chrome('./chromedriver')
driver.get("https://www.finlandiahiihto.fi/Tulokset/Tulosarkisto")
print(driver.title)
search_bar = driver.find_element_by_id("dnn_ctr1025_Etusivu_cmdHaeTulokset").click()
time.sleep(2)

numero = 0
id = "dnn_ctr1025_Etusivu_dgrTulokset_ctl00__"
id = id + str(numero)
time.sleep(1)
print(driver.page_source)
#while(driver.find_element_by_id(id)):
#    resultinformation = driver.find_element_by_id(id)
#    print(resultinformation.text)
#    id = "dnn_ctr1025_etusivu_dgrtulokset_ctl00__"
#    id = id + str(numero)
#    numero += 1
#element = driver.find_element_by_class_name("rgRow")
f=open("data.txt", "w+", encoding='utf-8')
f.write(driver.page_source)
f.close()
driver.close()