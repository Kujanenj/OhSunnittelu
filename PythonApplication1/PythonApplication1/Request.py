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
while(driver.find_element_by_id(id)):
    resultInformation = driver.find_element_by_id(id)
    print(resultInformation.text)
    id = "dnn_ctr1025_Etusivu_dgrTulokset_ctl00__"
    id = id + str(numero)
    numero += 1
#element = driver.find_element_by_class_name("rgRow")
driver.close()