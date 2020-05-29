module Query = [%relay.query
  {|
query GithubFileContentEditorQuery($owner: String!) {
  repository(owner: $owner, name: "Nutrition-App") {
    description
    folder: object(expression: "1473635:client/src/components/Food.js") {
      __typename
      ... on Blob {
        text
      }
    }
  }
}
|}
];

[@react.component]
let make = () => {
  let queryData = Query.use(~variables={owner: "CRMIII"}, ());

  switch (queryData.repository) {
  | Some(repository) =>
    <Editor
      value={
        switch (repository.folder) {
        | Some(description) =>
          switch (description) {
          | `Blob(blob) =>
            switch (blob.text) {
            | Some(content) => content
            | None => ""
            }
          | `UnselectedUnionMember(blankValue) => blankValue
          }
        | None => ""
        }
      }
    />
  | None => React.null
  };
};