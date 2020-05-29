[@bs.module "react-codemirror2"] [@react.component]
external make:
  (
    ~value: string,
    ~options: option(Js.t({..}))=?,
    ~onBeforeChange: (_, _, string) => unit=?
  ) =>
  React.element =
  "Controlled";