#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from tkinter import *
from random import *

name_list = ['曹琳', '陈启杭', '丁杰睿', '杜泽', '冯佳斌', '高婉蓥', '韩旭', '邵欣妍', '王叶佳蕙', '李枭杰', '郞峻磊', '刘子涵', '沈芯苗', '石皓文', '李语阳', '王矜语', '侯瑞曦', '潘雨轩', '占城茜', '何政融', '杨胡轩', '蒋炫屹', '郑谊霖', '徐喆', '叶瑾瑄', '黄飞扬', '杨雨彤', '吴奥然']

set_name = ''

def set_the_name() :
    global set_name
    set_name = entry.get()
    
    entry.place_forget()
    button.place_forget()
    text.focus_set()

def show_name(event) :
    global set_name
    mode = event.keysym
    
    if mode == 's' :
        entry.place(anchor = 'center', x = 225, y = 175)
        button.place(anchor = 'center', x = 225, y = 210)
        entry.delete(0, END)
        entry.focus_set()
    
    elif mode == 'p':
        text.config(text = set_name)
    
    else :
        name_id = getrandbits(32) % 28
        text.config(text = name_list[name_id])

window = Tk()
window.config(bg = '#87CEEB')
window.title("随机点名")
window.geometry("450x300")

text = Label(window, text = '按任意键随机点名', font = ('微软雅黑' , 20), bg = 'red')
entry = Entry(window)
button = Button(window, text = 'ok', command = set_the_name)

text.bind('<Key>', show_name)
text.focus_set()
text.place(anchor = 'center', x = 225, y = 125)

my_name = Label(window, text = 'powered by ShwStone')
my_name.pack(side = 'bottom')

window.mainloop()


