import threading
from selenium import webdriver #PIP INSTALL SELENIUM
from selenium.webdriver.firefox.service import Service
from selenium.webdriver.common.by import By
import time

def fill_form(driver):
    # Responsable
    name_field = driver.find_element(By.XPATH,
                                     '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[1]/div/div/div[2]/div/div[1]/div[2]/textarea')
    name_field.send_keys('Yocsan Luévano')
    option_field = driver.find_element(By.XPATH,
                                       '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[2]/div/div/div[2]/div/div/span/div/div[2]/label')
    option_field.click()
    print("Responsable filled")

    # Borracho
    name_field = driver.find_element(By.XPATH,
                                     '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[3]/div/div/div[2]/div/div[1]/div[2]/textarea')
    name_field.send_keys('Yocsan Luévano')
    option_field = driver.find_element(By.XPATH,
                                       '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[4]/div/div/div[2]/div/div/span/div/div[2]/label')
    option_field.click()
    print("Borracho filled")

    # Deportista
    name_field = driver.find_element(By.XPATH,
                                     '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[5]/div/div/div[2]/div/div[1]/div[2]/textarea')
    name_field.send_keys('Yocsan Luévano')
    option_field = driver.find_element(By.XPATH,
                                       '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[6]/div/div/div[2]/div/div/span/div/div[2]/label')
    option_field.click()
    print("Deportista filled")

    # Outfits
    name_field = driver.find_element(By.XPATH,
                                     '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[7]/div/div/div[2]/div/div[1]/div[2]/textarea')
    name_field.send_keys('Yocsan Luévano')
    option_field = driver.find_element(By.XPATH,
                                       '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[8]/div/div/div[2]/div/div/span/div/div[2]/label')
    option_field.click()
    print("Outfits filled")

    # Bailarin
    name_field = driver.find_element(By.XPATH,
                                     '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[9]/div/div/div[2]/div/div[1]/div[2]/textarea')
    name_field.send_keys('Yocsan Luévano')
    option_field = driver.find_element(By.XPATH,
                                       '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[10]/div/div/div[2]/div/div/span/div/div[2]/label')
    option_field.click()
    print("Bailarin filled")

    # Estudioso
    name_field = driver.find_element(By.XPATH,
                                     '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[11]/div/div/div[2]/div/div[1]/div[2]/textarea')
    name_field.send_keys('Yocsan Luévano')
    option_field = driver.find_element(By.XPATH,
                                       '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[12]/div/div/div[2]/div/div/span/div/div[2]/label')
    option_field.click()
    print("Estudioso filled")

    # Fifas
    name_field = driver.find_element(By.XPATH,
                                     '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[13]/div/div/div[2]/div/div[1]/div[2]/textarea')
    name_field.send_keys('Yocsan Luévano')
    option_field = driver.find_element(By.XPATH,
                                       '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[14]/div/div/div[2]/div/div/span/div/div[2]/label')
    option_field.click()
    print("Fifas filled")

    # Otaku
    name_field = driver.find_element(By.XPATH,
                                     '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[15]/div/div/div[2]/div/div[1]/div[2]/textarea')
    name_field.send_keys('Yocsan Luévano')
    option_field = driver.find_element(By.XPATH,
                                       '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[16]/div/div/div[2]/div/div/span/div/div[2]/label')
    option_field.click()
    print("Otaku filled")

    # Gamer
    name_field = driver.find_element(By.XPATH,
                                     '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[17]/div/div/div[2]/div/div[1]/div[2]/textarea')
    name_field.send_keys('Yocsan Luévano')
    option_field = driver.find_element(By.XPATH,
                                       '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[18]/div/div/div[2]/div/div/span/div/div[2]/label')
    option_field.click()
    print("Gamer filled")

    # Programador
    name_field = driver.find_element(By.XPATH,
                                     '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[19]/div/div/div[2]/div/div[1]/div[2]/textarea')
    name_field.send_keys('Chat GPT')
    option_field = driver.find_element(By.XPATH,
                                       '//*[@id="mG61Hd"]/div[2]/div/div[2]/div[20]/div/div/div[2]/div/div/span/div/div[2]/label')
    option_field.click()
    print("Programador filled")

    option_field = driver.find_element(By.XPATH, '//*[@id="mG61Hd"]/div[2]/div/div[3]/div[1]/div[1]/div')
    option_field.click()

    time.sleep(1)

def resend_form(driver):
    option_field = driver.find_element(By.XPATH, '/html/body/div[1]/div[2]/div[1]/div/div[4]/a[2]')
    option_field.click()
    time.sleep(1)
    fill_form(driver)

def submit_form(thread_id):
    service = Service('assets\geckodriver-v0.35.0-win-aarch64\geckodriver') #CAMBIAR RUTA 
    driver = webdriver.Firefox(service=service)
    driver.get('https://docs.google.com/forms/d/e/1FAIpQLSfN9M5u88p1YXp0fNU63lviZYk7yuYmWqavP2xSBnzJjiuBNA/viewform')

    try:
        fill_form(driver)
        print(f"Thread {thread_id}: Initial form submitted")

        while True:
            resend_form(driver)
            print(f"Thread {thread_id}: Form resubmitted")
    except Exception as e:
        print(f"Thread {thread_id} encountered an error: {str(e)}")
    finally:
        driver.quit()

def main():
    num_threads = 2  # CAMBIAR HILOS DEPENDIENDO DE SUS PCS
    threads = []

    for i in range(num_threads):
        thread = threading.Thread(target=submit_form, args=(i,))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

#if _name_ == "_main_":
    main()