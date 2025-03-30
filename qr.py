import qrcode

img=qrcode.make("https://www.linkedin.com/in/royrajdeep/")
img.save("qr.png", "PNG")

// you can give any link inside those "double-quotes"
