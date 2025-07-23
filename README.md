# STM32 Time Clock

Project **STM32 Time Clock** – một ví dụ điển hình về thiết kế đồng hồ thời gian thực sử dụng STM32, được triển khai với:

- 🕒 **I²C**: giao tiếp với module RTC để cập nhật thời gian chính xác
- 🖥️ **OLED**: hiển thị thời gian, trạng thái hệ thống
- 🧵 **FreeRTOS**: quản lý song song các task như đọc RTC, cập nhật OLED, xử lý UART 
- 📡 **UART**: giao tiếp với máy tính/thiết bị ngoài để cấu hình hoặc debug

---

## ⚙️ Tính năng chính

1. **Task RTC**:  
   - Giao tiếp I²C với module RTC (DS3231/DS1307...)  
   - Đọc dữ liệu từng giây  

2. **Task Hiển thị**:  
   - Cập nhật thời gian lên màn OLED qua I²C  
   - Độc lập với task RTC nhờ FreeRTOS  

3. **UART Task**:  
   - Nhận dữ liệu debug định dạng “HH:MM:SS”

## ♻️ Thư viện có thể tái sử dụng

- `RTC`: driver giao tiếp và xử lý RTC qua I²C  
- `SSD1306`: driver hiển thị trên OLED  
→ Bạn có thể **tách riêng** hai thư viện này để tái sử dụng trong các project khác.
  
