/* @generated */

module Types = {
  type response_repository_folder_Blob = {text: option(string)};
  type response_repository_folder = [
    | `Blob(response_repository_folder_Blob)
    | `UnselectedUnionMember(string)
  ];
  type response_repository = {
    description: option(string),
    folder:
      option(
        [
          | `Blob(response_repository_folder_Blob)
          | `UnselectedUnionMember(string)
        ],
      ),
  };

  type response = {repository: option(response_repository)};
  type refetchVariables = {owner: option(string)};
  let makeRefetchVariables = (~owner=?, ()): refetchVariables => {
    owner: owner,
  };
  type variables = {owner: string};
};

let unwrap_response_repository_folder:
  {. "__typename": string} =>
  [
    | `Blob(Types.response_repository_folder_Blob)
    | `UnselectedUnionMember(string)
  ] =
  u =>
    switch (u##__typename) {
    | "Blob" => `Blob(u->Obj.magic)
    | v => `UnselectedUnionMember(v)
    };

let wrap_response_repository_folder:
  [
    | `Blob(Types.response_repository_folder_Blob)
    | `UnselectedUnionMember(string)
  ] =>
  {. "__typename": string} =
  fun
  | `Blob(v) => v->Obj.magic
  | `UnselectedUnionMember(v) => {"__typename": v};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"repository":{"n":""},"repository_description":{"n":""},"repository_folder":{"n":"","u":"response_repository_folder"},"repository_folder_blob_text":{"n":""}}} |json}
  ];
  let responseConverterMap = {
    "response_repository_folder": unwrap_response_repository_folder,
  };
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let variablesConverterMap = ();
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

type preloadToken;

module Utils = {
  open Types;
  let makeVariables = (~owner): variables => {owner: owner};
};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "owner",
    "type": "String!",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "Literal",
    "name": "name",
    "value": "Nutrition-App"
  },
  {
    "kind": "Variable",
    "name": "owner",
    "variableName": "owner"
  }
],
v2 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "description",
  "args": null,
  "storageKey": null
},
v3 = [
  {
    "kind": "Literal",
    "name": "expression",
    "value": "1473635:client/src/components/Food.js"
  }
],
v4 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "__typename",
  "args": null,
  "storageKey": null
},
v5 = {
  "kind": "InlineFragment",
  "type": "Blob",
  "selections": [
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "text",
      "args": null,
      "storageKey": null
    }
  ]
},
v6 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "id",
  "args": null,
  "storageKey": null
};
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "GithubFileContentEditorQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "repository",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "Repository",
        "plural": false,
        "selections": [
          (v2/*: any*/),
          {
            "kind": "LinkedField",
            "alias": "folder",
            "name": "object",
            "storageKey": "object(expression:\"1473635:client/src/components/Food.js\")",
            "args": (v3/*: any*/),
            "concreteType": null,
            "plural": false,
            "selections": [
              (v4/*: any*/),
              (v5/*: any*/)
            ]
          }
        ]
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "GithubFileContentEditorQuery",
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "repository",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "Repository",
        "plural": false,
        "selections": [
          (v2/*: any*/),
          {
            "kind": "LinkedField",
            "alias": "folder",
            "name": "object",
            "storageKey": "object(expression:\"1473635:client/src/components/Food.js\")",
            "args": (v3/*: any*/),
            "concreteType": null,
            "plural": false,
            "selections": [
              (v4/*: any*/),
              (v6/*: any*/),
              (v5/*: any*/)
            ]
          },
          (v6/*: any*/)
        ]
      }
    ]
  },
  "params": {
    "operationKind": "query",
    "name": "GithubFileContentEditorQuery",
    "id": null,
    "text": "query GithubFileContentEditorQuery(\n  $owner: String!\n) {\n  repository(owner: $owner, name: \"Nutrition-App\") {\n    description\n    folder: object(expression: \"1473635:client/src/components/Food.js\") {\n      __typename\n      ... on Blob {\n        text\n      }\n      id\n    }\n    id\n  }\n}\n",
    "metadata": {}
  }
};
})() |json}
];

include ReasonRelay.MakePreloadQuery({
  type variables = Types.variables;
  type queryPreloadToken = preloadToken;
  let query = node;
  let convertVariables = Internal.convertVariables;
});
