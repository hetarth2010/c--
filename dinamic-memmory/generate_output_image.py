from pathlib import Path
from PIL import Image, ImageDraw, ImageFont

text_path = Path("output.txt")
image_path = Path("output-screenshot.png")

lines = text_path.read_text(encoding="utf-8").splitlines()

width, height = 1400, 900
image = Image.new("RGB", (width, height), "white")
draw = ImageDraw.Draw(image)

font = None
font_candidates = [
    "C:/Windows/Fonts/consola.ttf",
    "C:/Windows/Fonts/CascadiaMono.ttf",
    "C:/Windows/Fonts/lucon.ttf",
]

for candidate in font_candidates:
    try:
        font = ImageFont.truetype(candidate, 22)
        break
    except Exception:
        pass

if font is None:
    font = ImageFont.load_default()

margin_x, margin_y = 40, 40
x, y = margin_x, margin_y

for line in lines:
    draw.text((x, y), line, fill="black", font=font)
    y += 32

image.save(image_path)
print(f"Created screenshot: {image_path}")
