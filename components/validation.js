import * as Yup from "yup";

// https://github.com/jquense/yup
export const validationSchema = Yup.object().shape({
  name: Yup.string().required("必填项：请输入昵称"),
  email: Yup.string()
    .email("请输入有效的电子邮件地址")
    .required("必填项：请输入已注册的电子邮件"),
  password: Yup.string()
    .required("必填项：请输入密码")
    .min(6, "密码长度至少为6个字符"),
  confirmPassword: Yup.string()
    .required("请确认密码")
    .oneOf([Yup.ref("password")], "密码和确认密码不匹配"),
});
