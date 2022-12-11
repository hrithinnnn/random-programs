import pyautogui
import time
import webbrowser as wb
wb.open("https://web.whatsapp.com/")
time.sleep(5)
pyautogui.typewrite("hello") 
pyautogui.press("enter")
