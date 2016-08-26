import os

import PIL
from PIL import Image

img = Image.open('equipment_slots.png')

x = 0
y = 0

for i in range(0, 20):

    img.crop((x, y, x + 40, y + 40)).save('slot-' + str(i) + '.png')

    x += 40

    if x >= img.size[0]:
        x = 0
        y += 40