
let exampleSnippet = {|import React from "react";
import PropTypes from 'prop-types';
import { Card } from "semantic-ui-react";
import { capitalize, join, split, map, flow } from "lodash";

// takes string and splits into words based on spaces
const splitOnSpaces = str => split(str, " ");

// takes an array of words and capitalizes first letter, returns array
const capitilizeWordList = wordList => map(wordList, capitalize);

// takes an array of string and joins them with spaces
const joinOnSpaces = list => join(list, " ");

const formatName = flow(splitOnSpaces, capitilizeWordList, joinOnSpaces);

const Food = ({ brand, name }) => {
  return (
    <Card.Content>
      <Card.Header>{`${brand} ${formatName(name)}`}</Card.Header>
    </Card.Content>
  );
};

Food.propTypes = {
  brand: PropTypes.number.isRequired,
  name: PropTypes.string.isRequired,
};

export default Food;
|};

type state = {editorContent: string};

type action =
  | OnTextChange(string);

let initialState = {editorContent: exampleSnippet};

let reducer = (_, action) =>
  switch (action) {
  | OnTextChange(text) => {editorContent: text}
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  <main>
    <Editor
      value={state.editorContent}
      onChange={(value) => dispatch(OnTextChange(value))}
    />
  </main>;
};