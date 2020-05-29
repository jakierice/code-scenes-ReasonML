[%bs.raw {|require('codemirror/lib/codemirror.css')|}];
[%bs.raw {|require('codemirror/theme/lucario.css')|}];
[%bs.raw {|require('codemirror/mode/jsx/jsx')|}];

[@react.component]
let make = (~onChange: option(string => unit)=?, ~value: string) => {
    <CodeMirror
      value
      options={"mode": "jsx", "theme": "lucario", "lineNumbers": true}
      onBeforeChange={(_editor, _data, content) =>
        switch (onChange) {
        | Some(onChange) => onChange(content)
        | None => ()
        }
      }
    />
};