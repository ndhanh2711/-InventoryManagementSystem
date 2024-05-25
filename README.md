# Ý tưởng thực hiện bài code
## Hệ thống quản lí xuất nhập kho
- Tạo một kho lưu trữ các mặt hàng có sẵn bằng mảng((cấp phát động) (Dùng C), còn trong C++ dùng vector cho tiện)
- Kho chứa tối đa được 100 mặt hàng, mỗi mặt hàng có các data( Tên sp, mã sp, số lượng, giá thành/1sp)
### Hệ thống sẽ có các chức năng
#### Hiển thị kho
      - Sử dụng MENU lựa chọn để làm giao diện cho hệ thống
      1. Hiển thị các mặt hàng tồn kho (Hệ thống sẽ thông báo các mặt hàng có số lượng quá ít trong kho( < 20sp )).
#### Xuất kho
      1. Xuất kho (Bạn sẽ cần nhập số lượng mặt hàng muốn xuất kho, sau đó hệ thống sẽ yêu cầu nhập thông tin xuất kho của từng loại mặt hàng (mã sp, số lượng))
      2. Nếu số lượng sp xuất kho vượt quá số lượng mặt hàng có trong kho, hệ thống tự động báo lỗi và yêu cầu nhập lại.
      3. Sau khi xuất kho, kho hàng tự động cập nhật thông tin cho người dùng
#### Nhập kho
      Tương tự nhập kho(Thêm yêu cầu nhập mã mặt hàng).
#### Sắp xếp các mặt hàng theo yêu cầu
      Chức năng này giúp phục vụ việc kiểm tra hàng hoá
      1. Tăng giảm theo giá thành
      2. Tăng giảm theo số lượng