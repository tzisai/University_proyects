# -*- coding: utf-8 -*-
"""
Created on Thu Oct  9 08:30:27 2025

@author: Isai Nuñez
"""

import numpy as np
import matplotlib.image as img

imgen = img.imread("sonic.jpg")


if imgen.max() > 1:
    imgen = imgen / 255.0


h, w = imgen.shape[:2]


new_image = np.zeros((h, w, 4))


negativo = 1 - imgen[:, :, :3]


new_image[:, :, :3] = negativo
new_image[:, :, 3] = 1

img.imsave("negas.jpg", new_image)
