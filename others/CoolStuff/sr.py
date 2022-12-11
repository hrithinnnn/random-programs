import speech_recognition as sr
import webbrowser as wb
r1=sr.Recognizer()
r2=sr.Recognizer()
r3=sr.Recognizer()
with sr.Microphone() as source:
    print("speak now")
    audio=r3.listen(source)
    print(r2.recognize_google(audio))
    if 'YouTube' in r2.recognize_google(audio):
        print("tell search")
        with sr.Microphone() as source:
            search=r2.listen(source)
            x=r2.recognize_google(search)
            print(x)
            wb.get().open_new("https://www.youtube.com/results?search_query="+x)
    if 'Google' in r1.recognize_google(audio):
        print("tell search")
        with sr.Microphone() as source:
            search=r1.listen(source)
            x=r1.recognize_google(search)
            print(x)
            wb.get().open_new("https://www.google.com/search?q="+x+"&ei=2PqpYvnhKrTFz7sPhYSF4AE&ved=0ahUKEwj5rfT-4q_4AhW04nMBHQVCARwQ4dUDCA4&uact=5&oq="+x+"&gs_lcp=Cgdnd3Mtd2l6EAMyCggAELEDEIMBEAoyCggAELEDEIMBEAoyCggAELEDEIMBEAoyCwguELEDEIMBENQCMgoIABCxAxCDARAKMgcIABDJAxAKMgUIABCSAzIFCAAQkgMyCAgAELEDEIMBMgoIABCxAxCDARAKOgoIABCxAxCDARBDOgsIABCABBCxAxCDAToRCC4QgAQQsQMQgwEQxwEQ0QM6CAgAEIAEELEDOgsILhCABBCxAxDUAjoECAAQQzoKCC4QxwEQowIQQzoHCC4QsQMQQzoECC4QQzoFCAAQgAQ6BwgAEMkDEEM6BwgAEIAEEApKBAhBGABKBAhGGABQywRY5h5g5CBoAXABeACAAWyIAeoGkgEDNC41mAEAoAEBsAEAwAEB&sclient=gws-wiz"+x)
                
