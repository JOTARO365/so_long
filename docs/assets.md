# Character & Asset Design — ประกายสีทอง

Reference style: pixel art chibi, 16×20 px base, SCALE×4 = 64×80 px
Tile size in-game: 64×64 px

---

## Color Palette

```
# Shared
SKIN     #E8C49A   ผิวอบอุ่น (Thai tone)
SKIN_S   #C8A07A   ผิวเงา
HAIR_D   #2C1810   ผมเข้ม
HAIR_H   #4A3020   ผมไฮไลต์

# แทน — ยมทูต (Player)
COAT     #1A1A2E   เสื้อคลุมดำ
COAT_L   #2E2E4E   ไฮไลต์
EYE_G    #C8D4FF   ดวงตาเรืองแสงขาว-น้ำเงิน (ผิดธรรมชาติ)

# เบล — วิญญาณ (Soul)
SHIRT_W  #EEF2FF   เสื้อเชิ้ตขาว (แต่งตัวมาขอแต่งงาน)
SHIRT_S  #C8D4E8   เงาเสื้อ
PANTS    #2C3E50   กางเกงสีเข้ม
SOUL_G   #A8D8F0   ออร่าวิญญาณ (light blue)

# Collectible — ประกายสีทอง
GOLD     #FFD700
GOLD_D   #FFA500
GOLD_B   #FFFACD   แสงสว่างกลาง

# Exit — ประตูภพ
GATE_D   #4A0E8F   กรอบม่วงเข้ม
GATE_G   #9B59B6   กรอบม่วงอ่อน
GATE_C   #E8DAEF   แสงภายใน

# Environment
WALL     #1A1A2E
WALL_L   #16213E
FLOOR    #2C1810
FLOOR_L  #3D2318
```

---

## แทน — ยมทูต (Player)

คอนเซปต์: ชายหนุ่มธรรมดาที่กลายเป็นยมทูต
แต่งตัวด้วยเสื้อคลุมสีดำ ผมดำ ผิวอบอุ่น
ดวงตาเรืองแสงขาว-น้ำเงินเล็กน้อย — สัญลักษณ์ว่าเขาไม่ใช่มนุษย์แล้ว

```
Pixel grid 16×20:

         ░HHHHHHHH░      H = HAIR_D
        ░HHhHHHhHHH░
       ░HHHHhHHhHHHH░    h = HAIR_H
       ░HH SSSSSSSS Hh░  S = SKIN
       ░HH SSSSSSSS Hh░
       ░HH sWSSSSWs Hh░  W = EYE_G (glow)
       ░HH SSSSSSSS Hh░
       ░HH SSSSSSSS Hh░
        ░HHHHHHHHhH░
         ░CCcCCCCc░      C = COAT
        ░CCCCCCCCCCCc░
       ░CC░░░░░░░░░░CC░   แขนออกด้านข้าง
       CC░░░░░░░░░░CC
        ░CCCCCCCCc░
        ░CCCCCCCCc░
        ░CCcCCCCc░
        ░CCc░CCc░         ขา
        ░CCc░CCc░
        ░NNc░NNc░         N = COAT darkest (รองเท้า)
```

---

## เบล — วิญญาณ (Soul / Companion)

คอนเซปต์: ชายหนุ่ม แต่งตัวดี เสื้อเชิ้ตขาว กางเกงสีเข้ม
แต่งตัวมาเพื่อขอแต่งงาน แต่ไม่ทันได้
ร่างกายมีออร่าสีฟ้าจางๆ รอบตัว — บอกว่าเป็นวิญญาณ

```
Pixel grid 16×20:

         ░HHHHHHHH░
        ░HHhHHHhHHH░
       ░HHHHhHHhHHHH░
       ░HH SSSSSSSS Hh░
       ░HH SSSSSSSS Hh░
       ░HH sESSSSEs Hh░   E = ดวงตาปกติสีเข้ม
       ░HH SSSSSSSS Hh░
       ░HH SSSSSSSS Hh░
        ░HHHHHHHHhH░
         ░TTtTTTTt░        T = SHIRT_W (ขาว)
        ░TTTTTTTTTTTt░
       ░TT░░░░░░░░░░TT░
       TT░░░░░░░░░░TT
        ░TTTTTTTTt░
        ░PPPPPPPPp░        P = PANTS
        ░PPpPPPPp░
        ░PPp░PPp░          ขา
        ░PPp░PPp░
        ░ppp░ppp░
```

Soul aura = 1px border สีฟ้าจางๆ รอบตัวละคร (เพิ่มโดย add_aura())

---

## Collectible — ประกายสีทอง (C)

แสดงเป็น ดวงแสงสีทองกลมๆ เรืองแสง
ตัวแทนของ "ประกายสีทอง" ที่ใส่ลงเยือกแก้ว

```
16×16:

    ....oooooooo....
    ...oooLLLooo....
    ..ooLLLLLLLoo...
    ..oLLLKKLLLLo...
    ..oLLKKKKLLLo...   K = bright centre
    ..oLLKKKKLLLo...
    ..ooLLLLLLLoo...
    ...oooLLLooo....
    ....oooooooo....
```

Colors: o=#FFA500, L=#FFD700, K=#FFFACD

Animation: 2 frame — กลมเล็ก / กลมใหญ่ (pulse glow)

---

## Exit — ประตูภพ (E)

ประตูโค้ง เรืองแสงสีม่วง ยืนบนเสาสองต้น

```
16×18:

    ......YYYY......   ← จุดสูงสุดของโค้ง
    ....YYyyyyYY....
    ...YyyZZZZyyY...
    ..YyyZZZZZZyyY..
    .YyyZZZZZZZZyyY.
    .YyZZZZZZZZZZyY.
    .YyZZZZWWZZZZyY.   W = bright centre
    .YyZZZZWWZZZZyY.
    .YyZZZZZZZZZZyY.
    .YyZZZZZZZZZZyY.
    .YyZZZZZZZZZZyY.
    .YyZZZZZZZZZZyY.
    .YYYYYYYYYYYYYY.   ← ฐานโค้ง
    ....YYY..YYY....   ← เสาซ้าย / ขวา
    ....YYY..YYY....
    ....YYY..YYY....
    ....YYY..YYY....
    ................
```

---

## Tiles — Environment

### Wall (1) — ผนังบ้าน
```
VVVVVVVVVVVVVVVV
VvvvvvvvVvvvvvvV
...
```
Colors: WALL #1A1A2E + WALL_L #16213E

### Floor (0) — พื้นไม้
```
FfFFfFFFfFFF...
```
Colors: FLOOR #2C1810 + FLOOR_L #3D2318

---

## XPM File List

```
textures/
├── player.xpm       แทน idle frame 1
├── player2.xpm      แทน idle frame 2
├── soul.xpm         เบล frame 1
├── soul2.xpm        เบล frame 2
├── collect.xpm      ประกายสีทอง frame 1
├── collect2.xpm     ประกายสีทอง frame 2 (glow)
├── exit.xpm         ประตูภพ
├── wall.xpm         ผนัง
└── floor.xpm        พื้น
```
