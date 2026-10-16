# Face Recognition using ESP32-CAM

Diploma **capstone project** (Electronics & Telecommunication Engineering, Government Polytechnic Solapur, academic year 2025–26). An **AI Thinker ESP32-CAM** module provides the camera and Wi-Fi web server, and a browser dashboard (**"FaceRecog"**) detects faces, registers new people and recognises them as **known or unknown** in real time.

The project was designed as a low-cost base for **security and attendance systems** (office / college attendance, access control, smart-home security).

## How it works

```
OV2640 camera -> ESP32-CAM (Wi-Fi camera web server, Arduino firmware)
   -> PC / laptop browser -> FaceRecog dashboard (HTML + CSS + JavaScript)
   -> face-api.js: face detection, 68-point landmarks, face descriptors
   -> match against saved faces -> green box + name (known) or red box (unknown)
```

**Firmware (ESP32-CAM, Arduino IDE).** Initialises the AI Thinker camera (JPEG, QVGA 320x240), connects to Wi-Fi, starts the camera server and prints the board's IP address on the Serial Monitor (115200 baud). The board is flashed through an FTDI USB-to-serial adapter with GPIO0 tied to GND during upload.

**Dashboard (browser).** Uses [face-api.js](https://github.com/justadudewhohacks/face-api.js) with three models: SSD MobileNet v1 (detection, minimum confidence 0.6), a 68-point face landmark net and a face recognition net. A `FaceMatcher` with a 0.6 distance threshold compares each detected face to the saved ones. Detection runs every 80 ms.

**Registering a face.** Enter a name, press *Capture & Save*, and the face descriptor is stored in the browser's `localStorage` so it is available next time.

## Features

- Live face detection with bounding boxes
- Add new people from the dashboard (name + capture)
- Known (green) / Unknown (red) labels on the live view
- Saved faces reloaded automatically on the next visit
- Pages: Dashboard, *What is Face Recog?*, About / Student Info

## Hardware

| Component | Role |
| --- | --- |
| AI Thinker ESP32-CAM (OV2640 camera, Wi-Fi) | Image capture and Wi-Fi camera server |
| FTDI USB-to-serial adapter | Programming the ESP32-CAM |
| 5 V supply (at least 2 A recommended) | Stable power during streaming |
| PC / laptop with a browser | Runs the dashboard |

## Tools

Arduino IDE (ESP32 board support, ESP32-CAM library), Visual Studio, HTML/CSS/JavaScript, face-api.js. The project report also covers OpenCV and Python as background for face detection and recognition.

## Documentation

The repository contains project documentation as PDF. The full capstone report (introduction, literature survey, scope, methodology, designs and working, results and applications) is the primary reference for this work.

[ESP32_CAM_Face_Recognition_Report (PDF)](ESP32_CAM_Face_Recognition_Report%20%282%29.pdf)

## Status

This is a student prototype. Source files (ESP32 firmware and dashboard page) are being organised for upload. No recognition accuracy figure is claimed.

## Privacy

Only use face data of people who have agreed to it. Do not publish Wi-Fi credentials or personal photos.

## Author

**Munazza Hawaldar**, Diploma in Electronics & Telecommunication Engineering (2026)
[LinkedIn](https://www.linkedin.com/in/munazza-hawaldar-644b0041a)
