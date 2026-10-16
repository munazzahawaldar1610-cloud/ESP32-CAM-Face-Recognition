# ESP32-CAM Face Recognition System

A diploma-level **embedded systems + IoT + computer vision** prototype. An AI Thinker **ESP32-CAM** streams live video over Wi-Fi to a Python application, which detects faces (Haar Cascade), recognises known people (LBPH) and shows the result on a **Flask** web dashboard.

> **Student prototype.** Built as an Electronics & Telecommunication Engineering diploma project to demonstrate how embedded hardware, networking and classical computer vision fit together. It is not production-grade or security-certified, and no recognition accuracy is claimed beyond what you measure on your own test data.

## Features

- Live video streaming from the ESP32-CAM over Wi-Fi (MJPEG)
- Real-time face detection with an OpenCV Haar Cascade classifier
- Known / Unknown face recognition with the LBPH recognizer
- Bounding boxes and name labels drawn on the live feed
- Browser dashboard (Flask + HTML/CSS) to view the stream
- One-click model retraining from the dashboard
- Laptop-webcam fallback for development without hardware

## How it works

```
ESP32-CAM  ->  Wi-Fi (MJPEG /stream)  ->  Python + OpenCV
   ->  Haar Cascade face detection  ->  LBPH face recognition
   ->  Known / Unknown + name label drawn on frame
   ->  Flask /video_feed  ->  browser dashboard
```

The Flask app exposes `/video_feed` (annotated MJPEG stream), `/status` (JSON) and `/train` (POST, retrain the model).

## Tech stack

| Area | Tools |
| --- | --- |
| Hardware | AI Thinker ESP32-CAM, USB-to-TTL (FTDI) programmer, 5 V supply |
| Firmware | Arduino IDE, C++ |
| Vision | Python, OpenCV (`opencv-contrib-python` for `cv2.face`), NumPy |
| Web | Flask, HTML/CSS |
| Network | Wi-Fi (2.4 GHz), MJPEG over HTTP |

## Documentation

The full write-up (problem statement, objectives, architecture, hardware and software requirements, setup steps, how Haar Cascade and LBPH work, troubleshooting, limitations and future work) is in the project report:

[ESP32_CAM_Face_Recognition_Report (PDF)](ESP32_CAM_Face_Recognition_Report%20%282%29.pdf)

## Limitations and possible improvements

- Haar Cascade + LBPH are classical methods and are sensitive to lighting, pose and image quality
- Works best with a small, well-lit training set per person
- Possible next steps: a deep-learning detector or recogniser, better low-light handling, and logging of recognition events

## Privacy and safety

- Only use face data from people who have agreed to it
- Never commit real Wi-Fi credentials or personal photos to a public repository

## Author

**Munazza Hawaldar**, Diploma in Electronics & Telecommunication Engineering (2026)
[LinkedIn](https://www.linkedin.com/in/munazza-hawaldar-644b0041a)
